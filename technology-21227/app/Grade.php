<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Grade extends Model
{
  public function classrooms() {
    return $this->hasMany('App\Classroom', 'grade_id', 'id');
  }

  public function courses() {
    return $this->hasMany('App\Course', 'grade_id', 'id');
  }

}
