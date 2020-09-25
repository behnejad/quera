<?php

require __DIR__.'/vendor/autoload.php';
use Firebase\JWT\JWT;

define('TOKEN_LIFETIME', 60);
define('SECRET', 'ABCSDGWER@#%$@#');
header('Content-Type: application/json');
function checkLogin()
{
    $username = $_POST['username'];
    $password = $_POST['password'];
    $users = json_decode(file_get_contents(__DIR__.'/users.json'), true);
    foreach ($users as $user) {
        if ($user['username'] == $username && $user['password'] == $password) {
            echo json_encode(['type' => 'login_success', 'token' => JWT::encode(['time' => time(), 'user' => $user['ID']], SECRET)]);
            die;
        }
    }
    echo json_encode(['type' => 'login_failure', 'token' => '']);
}
function getData()
{
    $token = getBearerToken();
    if (empty($token)) {
        http_response_code(403);
        die;
    }

    try {
        $data = (array) JWT::decode($token, SECRET, ['HS256']);
        if ($data['time'] + TOKEN_LIFETIME < time()) {
            http_response_code(401);
            echo 'EXPIRED_TOKEN';
            die;
        }
        $users = json_decode(file_get_contents(__DIR__.'/users.json'), true);
        foreach ($users as $user) {
            if ($data['user'] == $user['ID']) {
                echo json_encode($user['keys']);
                die;
            }
        }
    } catch (Exception $e) {
        http_response_code(401);
        echo 'INVALID_TOKEN';
        die;
    }
}
if (isset($_GET['f'])) {
    switch ($_GET['f']) {
        case 'login':
            checkLogin();
            break;
        case 'getData':
            getData();
            break;
    }
}

function getAuthorizationHeader()
{
    $headers = null;
    if (isset($_SERVER['Authorization'])) {
        $headers = trim($_SERVER['Authorization']);
    } elseif (isset($_SERVER['HTTP_AUTHORIZATION'])) { //Nginx or fast CGI
        $headers = trim($_SERVER['HTTP_AUTHORIZATION']);
    } elseif (function_exists('apache_request_headers')) {
        $requestHeaders = apache_request_headers();
        // Server-side fix for bug in old Android versions (a nice side-effect of this fix means we don't care about capitalization for Authorization)
        $requestHeaders = array_combine(array_map('ucwords', array_keys($requestHeaders)), array_values($requestHeaders));
        //print_r($requestHeaders);
        if (isset($requestHeaders['Authorization'])) {
            $headers = trim($requestHeaders['Authorization']);
        }
    }

    return $headers;
}
/**
 * get access token from header.
 * */
function getBearerToken()
{
    $headers = getAuthorizationHeader();
    // HEADER: Get the access token from the header
    if (!empty($headers)) {
        if (preg_match('/Bearer\s(\S+)/', $headers, $matches)) {
            return $matches[1];
        }
    }

    return null;
}
