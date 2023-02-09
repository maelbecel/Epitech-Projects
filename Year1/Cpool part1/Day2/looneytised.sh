#!/bin/bash
egrep "theo1|arnaud1|steven1|pierre-jean"  | sed -r 's/theo1/Wile E. Coyote/gi' | sed -r 's/steven1/Daffy Duck/gi' | sed -r 's/arnaud1/Porky Pig/gi' | sed -r 's/pierre-jean/Marvin the Martian/gi'
