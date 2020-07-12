const express = require('express');
const routes = express.Router();

//import controlles
const ledController = require('../controller/LedController');

//======================================================================
//Execute method controller
//======================================================================
routes.get('/led', ledController.index);

module.exports = routes;