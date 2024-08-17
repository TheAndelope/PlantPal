from flask import Flask, render_template, request, redirect, url_for, send_from_directory

app = Flask(__name__)

# Home route
@app.route('/')
def home():
    return render_template('index.html')

# Example static file route (not usually necessary unless you have custom handling)
@app.route('/static/<path:filename>')
def custom_static(filename):
    return send_from_directory('static', filename)

# Example file upload route
@app.route('/upload', methods=['POST'])
def upload_file():
    if 'file' not in request.files:
        return redirect(url_for('home'))
    file = request.files['file']
    if file.filename == '':
        return redirect(url_for('home'))
    if file:
        filepath = f'static/uploads/{file.filename}'
        file.save(filepath)
        return f'File uploaded to {filepath}'

if __name__ == '__main__':
    app.run(debug=True)
