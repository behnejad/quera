import React, { useState } from 'react';
import Input from './Input';
import data from './cities.json';

function App() {
   const [hint, setHint] = useState('');
   const handleChange = (e) => {
      let res = data.find(city => city.startsWith(e.target.value))
      if (e.target.value === '') {
         setHint('')
      } else if (res !== undefined) {
         setHint(res)
      } 
      else {
         setHint('') 
      } 
   }

   return (
      <div>
         <Input handleChange={handleChange} hint={hint} />
      </div>
   )
}

export default App;
