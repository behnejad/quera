<?php

define('DB_NAME', '_db.sqlite');

function is_installed()
{
    return file_exists(__DIR__.'/'.DB_NAME);
}

function is_request_get()
{
    return $_SERVER['REQUEST_METHOD'] == 'GET';
}

function is_request_post()
{
    return $_SERVER['REQUEST_METHOD'] == 'POST';
}

function render($file, $data = [])
{
    $view = realpath(__DIR__.DIRECTORY_SEPARATOR.'views'.DIRECTORY_SEPARATOR.$file.'.php');

    extract($data);

    ob_start();

    require $view;

    echo ob_get_clean();
}

function render_error($message)
{
    render('message', [
        'title'   => 'error',
        'message' => $message,
    ]);

    die();
}

function render_success($message)
{
    render('message', [
        'title'   => 'success',
        'message' => $message,
    ]);
}
