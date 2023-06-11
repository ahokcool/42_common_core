<?php
# phantomjs.php

require_once('vendor/autoload.php');
#require_once 'lib/jonnyw/php-phantomjs/src/JonnyW/PhantomJs/Client.php';

use JonnyW\PhantomJs\Client;

// create a PhantomJS client
$client = Client::getInstance();

//alex test to fix stuff
$client->getEngine()->setPath('/usr/local/bin/phantomjs');

// set the default viewport size
$client->getEngine()->setViewportSize(1024, 768);

// navigate to the page
$request = $client->getMessageFactory()->createRequest('https://profile.intra.42.fr/users/astein', 'GET');
$response = $client->getMessageFactory()->createResponse();
$client->send($request, $response);

// extract the button element and click it
$button = $response->getContent()->getElementByCssSelector('.btn-login-student');
$button->click();

// get the updated content after the button click
$request = $client->getMessageFactory()->createRequest('https://profile.intra.42.fr/users/astein', 'GET');
$response = $client->getMessageFactory()->createResponse();
$client->send($request, $response);
echo $response->getContent();

