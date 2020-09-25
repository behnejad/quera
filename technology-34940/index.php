<?php

require_once 'functions.php';

if (!is_installed()) {
    render_error('Application is not installed');
}

function get_films()
{
    $db = new SQLite3(__DIR__.'/'.DB_NAME);
    $films_query = $db->query('SELECT * FROM "films"');
    $films = [];
    while ($row = $films_query->fetchArray(SQLITE3_ASSOC)) {
        $votes_sum = 0;
        $votes_count = 0;
        $votes_query = $db->query('SELECT "score" FROM "votes" WHERE "film_id"='.$row['id']);
        while ($row2 = $votes_query->fetchArray(SQLITE3_ASSOC)) {
            $votes_sum += $row2['score'];
            $votes_count++;
        }
        $votes_average = 0;
        if ($votes_count) {
            $votes_average = $votes_sum / $votes_count;
        }
        $films[] = ['film_id' => $row['id'], 'title' => $row['title'], 'votes_count' => $votes_count, 'average_score' => $votes_average];
    }
    $db->close();

    return $films;
}

render('index', [
    'films' => get_films(),
]);
