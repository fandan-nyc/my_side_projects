from flask import Flask
from block_chain import BlockChain


if __name__ == "__main__":
    app = Flask(__name__)
    app.run(host="0.0.0.0", port=5000)
