#!/usr/bin/node

import request from "request";

const movieID = process.argv[2];

request.get(
    `https://swapi-api.hbtn.io/api/films/${movieID}`,
    (error, response, body) => {
        if (error) {
            console.error(error);
        } else {
            const characters = JSON.parse(body).characters;
            characters.forEach((character) => {
                request.get(character, (error, response, body) => {
                    console.log(JSON.parse(body).name);
                });
            });
        }
    }
);
