// http-client.js
const http = require('http');

const url = 'http://localhost:3000';

// Make a GET request
http.get(url, (response) => {
  let data = '';

  // A chunk of data has been received.
  response.on('data', (chunk) => {
    data += chunk;
  });

  // The whole response has been received.
  response.on('end', () => {
    console.log('Response:', data);
  });
}).on('error', (error) => {
  console.error('Error:', error.message);
});
