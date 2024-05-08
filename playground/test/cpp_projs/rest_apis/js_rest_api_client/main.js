// Base URL for the REST API
const baseUrl = 'https://localhost:8082';

// Function to send a GET request
function getUsers() {
    fetch(`${baseUrl}/users`)
        .then(response => response.json())
        .then(data => console.log('GET Response:', data))
        .catch(error => console.error('Error fetching users:', error));
}

// Function to send a POST request
function createUser(newUser) {
    fetch(`${baseUrl}/users`, {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(newUser)
    })
        .then(response => response.json())
        .then(data => console.log('POST Response:', data))
        .catch(error => console.error('Error creating user:', error));
}

// Function to send a PUT request
function updateUser(userId, updatedUser) {
    fetch(`${baseUrl}/users/${userId}`, {
        method: 'PUT',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(updatedUser)
    })
        .then(response => response.json())
        .then(data => console.log('PUT Response:', data))
        .catch(error => console.error('Error updating user:', error));
}

// Function to send a DELETE request
function deleteUser(userId) {
    fetch(`${baseUrl}/users/${userId}`, {
        method: 'DELETE'
    })
        .then(response => console.log('DELETE Response:', response.status))
        .catch(error => console.error('Error deleting user:', error));
}

// Usage examples
getUsers(); // Fetch all users
createUser({ name: 'New User', username: 'new_user', email: 'new@user.com' }); // Create a new user
updateUser(1, { name: 'Updated User' }); // Update user with ID 1
deleteUser(1); // Delete user with ID 1
