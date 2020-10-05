<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Classroom extends Model
{
  public function teacher() {
    return $this->hasOne('App\Teacher', 'classroom_id', 'id');
  }

  public function students() {
    return $this->hasMany('App\Student', 'classroom_id', 'id');
  }

  public function grades() {
    return $this->belongsTo('App\Grade', 'grades_id', 'id');
  }

}
