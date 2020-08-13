#!/usr/bin/node

/* Import module request to get info from an API */
const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`;

const handleCharactersNames = () => {
  // Function to request asynchronously the characters in a StarWars film
  // and print it's names
  request(url, async (error, response, body) => {
    if (error) {
      console.log(error);
    } else {
      const chars = JSON.parse(body).characters;
      for (const idx in chars) {
        const res = await handleName(chars[idx]);
        console.log(res);
      }
    }
  });
};

const handleName = (url) => {
  // Funtion to return a promise with the names of the characters
  return new Promise((resolve, reject) => {
    request(url, (err, res, body) => {
      if (err) {
        reject(err);
      } else {
        resolve(JSON.parse(body).name);
      }
    });
  });
};

handleCharactersNames();
