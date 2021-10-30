from time import time
import hashlib
import requests
import json


class BlockChain(object):
    def __init__(self):
        self.chain = []
        self.transactions = []
        self.nodes = set()
        self.new_block(last_hash=1, proof=100)

    def add_peer(self, node):
        self.nodes.append(node)

    def verify_chain(self, chain):
        curr_pos = 1
        prev_block = chain[0]
        while curr_pos < len(chain):
            block = chain[curr_pos]
            if block["last_hash"] != self.hash(prev_block):
                return false
            if not self.validate_proof(prev_block['proof'], block['proof']):
                return false
            prev_block = block
            curr_pos += 1
        return True

    def consensus_algo(self):
        # check all peers
        peers = self.nodes
        chains = []
        max_length = len(self.chain)
        new_chain = []
        for peer in peers:
            curr_chain = requests.get(f'http://localhost:{peer}/chain')
            if curr_chain.status_code == 200:
                curr_len = curr_chain.json()["chain_length"]
                curr_chain = curr_chain.json()["chain"]
                if self.verify_chain(curr_chain) and curr_len > max_length:
                    max_length = curr_len
                    new_chain = curr_chain
        if new_chain:
            self.chain = new_chain
            return True
        return False

    def new_transaction_from_request(self, payload):
        return self.new_transaction(payload["sender"], payload["receiver"], payload["amount"])

    def new_transaction(self, sender, receiver, amount):
        # return the index of the block it will fit into
        self.transactions.append(
            {'sender': sender,
             "receiver": receiver,
             "amount": amount})
        return self.chain[-1]["index"] + 1

    def new_block(self, proof, last_hash=None):
        '''
        the block contains the structure like the following:
        {
          index:
          timestamp:
          transactions: []
          proof:
          last_hash:
        }
        '''
        block = {
            'index': len(self.chain) + 1,
            'timestamp': time(),
            'transactions': self.transactions,
            'proof': proof,
            'last_hash': last_hash or self.hash(self.chain[-1])
        }
        self.transactions = []
        self.chain.append(block)

    def proof_of_work(self, last_proof):
        proof = 0
        while self.validate_proof(last_proof, proof) == False:
            proof += 1
        return proof

    def validate_proof(self, last_proof, proof):
        guess = f'{last_proof}{proof}'.encode()
        guess_hash = hashlib.sha256(guess).hexdigest()
        return guess_hash[:4] == "0000"

    @staticmethod
    def hash(block):
        block_string = json.dumps(block, sort_keys=True).encode()
        return hashlib.sha256(block_string).hexdigest()
