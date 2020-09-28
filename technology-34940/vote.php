<?php

require_once 'functions.php';

if (!is_installed()) {
    render_error('Application is not installed');
}

function get_parameters($film_id)
{
    $db = new SQLite3(__DIR__.'/'.DB_NAME);
    $result = $db->query('SELECT "genre" FROM "films" WHERE "id" = '.$film_id);
    $genre = $result->fetchArray(SQLITE3_ASSOC);
    $genre = $genre['genre'];
    $result = $db->query('SELECT "id", "title" FROM "parameters" WHERE "genre" = "'.$genre.'"');
    $parameters = [];
    while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
        $parameters[] = $row;
    }
    $db->close();

    return $parameters;
}

function has_voted($film_id)
{
    $films = [];
    if (!empty($_COOKIE['films'])) {
        $films = json_decode($_COOKIE['films'], true);
    }

    return in_array($film_id, $films);
}

function submit_vote($film_id, $scores)
{
    $db = new SQLite3(__DIR__.'/'.DB_NAME);
    foreach ($scores as $parameter => $score) {
        if ($score < 1) {
            $score = 1;
        }
        if ($score > 5) {
            $score = 5;
        }
        $db->exec('INSERT INTO "votes" ("film_id", "parameter_id", "score") VALUES ('.$film_id.', '.$parameter.', '.$score.')');
    }
    $films = [];
    if (!empty($_COOKIE['films'])) {
        $films = json_decode($_COOKIE['films'], true);
    }
    $films[] = $film_id;
    $films = json_encode($films);
    setcookie('films', $films, time() + 86400, '/');
}

if (is_request_get()) {
    $film_id = $_GET['film_id'];

    if (has_voted($film_id)) {
        render_error('Duplicate Vote');
    }

    $parameters = get_parameters($film_id);

    render('vote', [
        'film_id'    => $film_id,
        'parameters' => $parameters,
    ]);
}

if (is_request_post()) {
    $film_id = $_POST['film_id'];

    if (has_voted($film_id)) {
        render_error('Duplicate Vote');
    }

    $scores = $_POST['scores'];

    submit_vote($film_id, $scores);

    render_success('Vote Submitted Successfully');
}
