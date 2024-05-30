document.getElementById('cadastroForm').addEventListener('submit', function(event) {
    event.preventDefault();
    const formData = new FormData(event.target);
    const data = {};
    formData.forEach((value, key) => {
        data[key] = value;
    });
    enviarParaGoogleDrive(data);
});

function limparFormulario() {
    document.getElementById('cadastroForm').reset();
}

function enviarParaGoogleDrive(data) {
    // Aqui você deve configurar a integração com a Google Drive API
    // Para simplificar, vamos apenas logar os dados no console
    console.log('Dados enviados para o Google Drive:', data);
}
