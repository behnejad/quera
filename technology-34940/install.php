<?php

require_once 'functions.php';

if (is_installed()) {
    render_error('Already installed');
}

function read_parameters()
{
    return json_decode(file_get_contents(__DIR__.'/data/parameters.json'), true);
}

function read_films()
{
    return json_decode(file_get_contents(__DIR__.'/data/films.json'), true);
}

if (file_exists(__DIR__.'/'.DB_NAME)) {
    render_error('Already installed');
}

$db = new SQLite3(__DIR__.'/'.DB_NAME);

// Create Tables
$db->exec('CREATE TABLE "parameters" ("id" INTEGER PRIMARY KEY, "title" TEXT NOT NULL UNIQUE, "genre" TEXT NOT NULL)');
$db->exec('CREATE TABLE films ("id" INTEGER PRIMARY KEY, "title" TEXT NOT NULL UNIQUE, "genre" TEXT NOT NULL)');
$db->exec('CREATE TABLE votes ("film_id" INTEGER NOT NULL, "parameter_id" INTEGER NOT NULL, "score" INTEGER NOT NULL)');

// Fill Tables Initial Data
$films = read_films();
foreach ($films as $film) {
    $db->exec('INSERT INTO "films" ("title", "genre") VALUES("'.$film['title'].'", "'.$film['genre'].'");');
}

$parameters = read_parameters();
foreach ($parameters as $parameter) {
    $db->exec('INSERT INTO "parameters" ("title", "genre") VALUES("'.$parameter['title'].'", "'.$parameter['genre'].'");');
}

$db->close();

render_success('Installed successfully');
