from flask import Flask
from plantAI import create_text  # Import your existing function

app = Flask(__name__)

@app.route('/call_function', methods=['GET'])
def call_function():
    result = create_text()  # Call the function
    return result  # Return the result as a string

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)  # Start Flask server, accessible on your network
