from flask import Flask, jsonify, request
from block_chain import BlockChain
from constants import REQUIRED_TRANSACTION_KEYS
from uuid import uuid4
import sys

app = Flask(__name__)
block_chain = BlockChain()
node_identifier = str(uuid4()).replace("-", "")


def msg_response(msg, http_code):
    return jsonify({"msg": msg}), http_code


@app.route('/peer/add', methods=["POST"])
def add_peer():
    payload = request.get_json()
    peers = payload['peers']
    for i in peers:
        block_chain.nodes.add(i)
    return msg_response(f"current peers: {block_chain.nodes}", 200)


@app.route('/peer/resolve', methods=["GET"])
def resolve_peer():
    current_chain = block_chain.chain
    resolve_result = block_chain.consensus_algo()
    if not resolve_result:
        return msg_response("no update", 200)
    else:
        response = {'before': current_chain, "after": block_chain.chain}
        return jsonify(response), 200


@app.route("/chain", methods=["GET"])
def chain():
    response = {"chain": block_chain.chain, "chain_length": len(block_chain.chain)}
    return response, 200


@app.route("/transaction/new", methods=["POST"])
def new_transaction():
    def validate_required_keys(keys):
        for key in REQUIRED_TRANSACTION_KEYS:
            if key not in keys:
                return False, f'{key} is missing'
        return True, None
    payload = request.get_json()
    result, msg = validate_required_keys(payload.keys())
    if not result:
        return msg_response(msg, 400)
    chain_index = block_chain.new_transaction_from_request(payload)
    return msg_response(f'new transaction added at chain: {chain_index}', 200)


@app.route("/mine", methods=["GET"])
def mine():
    if not block_chain.transactions:
        return msg_response("no transactions, no mining", 400)
    # calculate the pow (proof of work)
    last_proof = block_chain.chain[-1]["proof"]
    curr_proof = block_chain.proof_of_work(last_proof)
    # record a new coin
    block_chain.new_transaction(0, node_identifier, 1)
    block_chain.new_block(curr_proof)
    return msg_response("new block created", 200)


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=sys.argv[1])
