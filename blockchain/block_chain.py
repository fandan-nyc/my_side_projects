from time import time
import hashlib
import json


class BlockChain(object):
    def __init__(self):
        self.chain = []
        self.transactions = []
        self.new_block(previous_hash=1, proof=100)

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
