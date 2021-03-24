#!/bin/bash

maxl=4

# create general header file guard
gheaderfile=spherical_harmonics.h
echo "#ifndef SPHERICAL_HARMONICS_H" > ${gheaderfile}
echo "#define SPHERICAL_HARMONICS_H" >> ${gheaderfile}
echo "" >> ${gheaderfile}

for l in $(seq 0 1 ${maxl});
do
   negl=$(echo "-${l}" | bc)
   for m in $(seq ${negl} 1 ${l});
   do
      msign=""
      absm=${m}
      if [[ ${absm} -lt 0 ]] ; then
         absm=$(echo "-1*${m}" | bc)
      fi
      if [[ ${m} -lt "0" ]] ; then
         msign="m"
      fi
      if [[ ${m} -gt "0" ]] ; then
         msign="p"
      fi
      filenamebase=spherical_harmonics_l${l}_m${msign}${absm}
      ./generate_spherical_harmonics.x --l=${l} --m=${m} --filebase=${filenamebase}

      echo "#include <${filenamebase}.h>" >> ${gheaderfile}
   done
done

# finish general header file guard
echo "" >> ${gheaderfile}
echo "#endif" >> ${gheaderfile}
