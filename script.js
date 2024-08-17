document.getElementById('fileInput').addEventListener('change', function(event) {
    const fileName = event.target.files[0] ? event.target.files[0].name : 'No file chosen';
    document.getElementById('fileName').textContent = fileName;
});

function uploadFile() {
    const fileInput = document.getElementById('fileInput');
    if (fileInput.files.length === 0) {
        alert('Please choose a file before uploading.');
    } else {
        // Handle the file upload process
        alert('File uploaded successfully: ' + fileInput.files[0].name);
    }
}
