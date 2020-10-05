<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Course extends Model
{
  public function grade() {
    return $this->belongsTo('App\Grade', 'grade_id', 'id');
  }

  public function scores() {
    return $this->hasMany('App\Score', 'course_id', 'id');
  }

}
