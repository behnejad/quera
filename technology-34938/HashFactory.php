<?php

class HashFactory
{
    private $strategies = [];

    public function register($name, HashStrategy $strategy)
    {
        $this->strategies[$name] = $strategy;
    }

    public function make($name)
    {
        if (!isset($this->strategies[$name])) {
            throw new Exception('Strategy Not Supported');
        }

        return $this->strategies[$name];
    }
}
