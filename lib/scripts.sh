awk -F, '{print "\"" $3 "\"" }' pokemonFormAbilities.csv | paste -d, -s - > formmons
awk -F, '{print "{\""$4"\",\""$5"\",\""$6"\"}" }' pokemonFormAbilities.csv | paste -d, -s - > formab
awk -F, '{print "{\""$1"\",\""$2"\",\""$3"\"}" }' pokemonAbilities.csv | paste -d, -s - > ab
awk '{print "\"" $0 "\""}' Species.txt | paste -d, -s - > mons
awk '{print "\"" $0 "\""}' Items.txt | paste -d, -s - > item
awk '{print "\"" $0 "\""}' Abilities.txt | paste -d, -s - > ab
awk '{print "\"" $0 "\""}' Moves.txt | paste -d, -s - > move
awk -F, '{print $1}' pokemonFormAbilities.csv | paste  -d, -s - > formmonsid
awk -F, '{print $2}' pokemonFormAbilities.csv | paste  -d, -s - > formid
———
