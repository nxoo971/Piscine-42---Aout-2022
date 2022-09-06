id -Gn $FT_USER | sed 's/ :/,/g' | sed 's/ /,/g' | tr --delete '\n'
