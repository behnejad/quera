<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Teacher extends Model
{
    public function classroom() {
      return $this->belongsTo('App\Classroom', 'classroom_id', 'id');
    }
}
