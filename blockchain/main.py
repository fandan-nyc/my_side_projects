from flask import Flask, jsonify, request
from block_chain import BlockChain
from constants import REQUIRED_TRANSACTION_KEYS
from uuid import uuid4

app = Flask(__name__)
block_chain = BlockChain()
node_identifier = str(uuid4()).replace("-","")


def msg_response(msg, http_code):
    return jsonify({"msg": msg}), http_code

@app.route("/chain", methods = ["GET"])
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
    if result == False:
        return msg_response(msg, 400)



if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
