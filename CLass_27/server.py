from flask import Flask, request, jsonify, render_template

app = Flask(__name__)

# Initialize the button state as off (0)
button_state = 0

@app.route('/get_state', methods=['GET'])
def get_state():
    return jsonify({"button_state": button_state})

if __name__ == '__main__':
    app.run(debug=True)
