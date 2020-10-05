<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Assignment extends Model
{
  public function students() {
    return $this->belongsToMany('App\Student', 'assignment_student', 'assignment_id', 'student_id');
  }
}
