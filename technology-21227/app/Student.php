<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Student extends Model
{
    public function classroom() {
      return $this->belongsTo('App\classroom', 'classroom_id', 'id');
    }

    public function assignments() {
      return $this->belongsToMany('App\Assignment', 'assignment_student', 'student_id', 'assignment_id');
    }

    public function scores() {
      return $this->hasMnay('App\Score', 'student_id', 'id');
    }

}
