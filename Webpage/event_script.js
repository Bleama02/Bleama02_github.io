const volunteerBtn = document.getElementById('volunteerBtn');
const eventBtn = document.getElementById('eventBtn');
const formTitle = document.getElementById('formTitle');
const volunteerForm = document.getElementById('volunteerForm');
const eventForm = document.getElementById('eventForm');

volunteerForm.style.display = "block";
eventForm.style.display = "none";

volunteerBtn.addEventListener('click', () => {
    volunteerBtn.classList.add('active');
    eventBtn.classList.remove('active');
    formTitle.textContent = "Create New Volunteer Opportunity";
    volunteerForm.style.display = "block";
    eventForm.style.display = "none";
});

eventBtn.addEventListener('click', () => {
    eventBtn.classList.add('active');
    volunteerBtn.classList.remove('active');
    formTitle.textContent = "Create New Event";
    volunteerForm.style.display = "none";
    eventForm.style.display = "block";
});

// Event listener for volunteer form submission
volunteerForm.addEventListener('submit', (event) => {
    event.preventDefault();

    const formData = new FormData(volunteerForm);

    fetch(volunteerForm.action, {
        method: 'POST',
        body: formData,
    })
    .then(response => {
        if (response.ok) {
            return response.text();
        } else {
            throw new Error('Network response was not ok.');
        }
    })
    .then(data => {
        alert(data);
    })
    .catch(error => {
        alert('An error occurred during submission.');
        console.error('There has been a problem with your fetch operation:', error);
    });
});

// Event listener for event form submission
eventForm.addEventListener('submit', (event) => {
    event.preventDefault();

    const formData = new FormData(eventForm);

    fetch(eventForm.action, {
        method: 'POST',
        body: formData,
    })
    .then(response => {
        if (response.ok) {
            return response.text();
        } else {
            throw new Error('Network response was not ok.');
        }
    })
    .then(data => {
        alert(data);
    })
    .catch(error => {
        alert('An error occurred during submission.');
        console.error('There has been a problem with your fetch operation:', error);
    });
});

document.addEventListener('DOMContentLoaded', function() {
    // Volunteer Form Add Organizer
    document.getElementById('addOrganizerBtnVolunteer').addEventListener('click', function() {
        let newOrganizer = document.getElementById('newOrganizerVolunteer').value;
        let organizersList = document.getElementById('organizersListVolunteer');

        if (newOrganizer && organizersList.children.length < 3) {
            let organizerElement = document.createElement('div');
            organizerElement.textContent = newOrganizer;
            organizerElement.classList.add('organizer-box');

            let hiddenInput = document.createElement('input');
            hiddenInput.type = 'hidden';
            hiddenInput.name = 'organizers[]';
            hiddenInput.value = newOrganizer;

            organizerElement.appendChild(hiddenInput);
            organizersList.appendChild(organizerElement);
            document.getElementById('newOrganizerVolunteer').value = '';
        } else if (organizersList.children.length >= 3) {
            alert("You can add a maximum of 3 organizers.");
        }
    });

    // Event Form Add Organizer
    document.getElementById('addOrganizerBtnEvent').addEventListener('click', function() {
        let newOrganizer = document.getElementById('newOrganizerEvent').value;
        let organizersList = document.getElementById('organizersListEvent');

        if (newOrganizer && organizersList.children.length < 3) {
            let organizerElement = document.createElement('div');
            organizerElement.textContent = newOrganizer;
            organizerElement.classList.add('organizer-box');

            let hiddenInput = document.createElement('input');
            hiddenInput.type = 'hidden';
            hiddenInput.name = 'organizers[]';
            hiddenInput.value = newOrganizer;

            organizerElement.appendChild(hiddenInput);
            organizersList.appendChild(organizerElement);
            document.getElementById('newOrganizerEvent').value = '';
        } else if (organizersList.children.length >= 3) {
            alert("You can add a maximum of 3 organizers.");
        }
    });

    // Volunteer Form Add Volunteer
    document.getElementById('addVolunteerBtn').addEventListener('click', function() {
        let newVolunteer = document.getElementById('newVolunteer').value;
        if (newVolunteer) {
            let volunteerElement = document.createElement('div');
            volunteerElement.textContent = newVolunteer;

            let hiddenInput = document.createElement('input');
            hiddenInput.type = 'hidden';
            hiddenInput.name = 'volunteers[]';
            hiddenInput.value = newVolunteer;

            volunteerElement.appendChild(hiddenInput);
            document.getElementById('volunteersList').appendChild(volunteerElement);
            document.getElementById('newVolunteer').value = '';
        }
    });
});