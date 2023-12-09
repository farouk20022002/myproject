document.addEventListener('DOMContentLoaded', function () {
    const loginBtn = document.getElementById('loginBtn');
    const popupWrapper = document.getElementById('popupWrapper');
    const closeIcon = document.getElementById('closeIcon');

    // Function to show the wrapper
    function showWrapper() {
        popupWrapper.style.display = 'flex';
    }

    // Function to hide the wrapper
    function hideWrapper() {
        popupWrapper.style.display = 'none';
    }

    // Hide the wrapper by default
    popupWrapper.style.display = 'none';

    // Show the wrapper when login button is clicked
    loginBtn.addEventListener('click', showWrapper);

    // Hide the wrapper when close icon is clicked
    closeIcon.addEventListener('click', hideWrapper);
});

