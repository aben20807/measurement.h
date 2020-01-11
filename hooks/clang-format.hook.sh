#!/usr/bin/env bash
RETURN=0
CLANG_FORMAT=$(which clang-format-6.0)
if [ $? -ne 0 ]; then
    echo "[!] clang-format-6.0 not installed. Unable to check source file format policy." >&2
    exit 1
fi

DIFF=$(which colordiff)
if [ $? -ne 0 ]; then
    DIFF=diff
fi

FILES=`git diff --cached --name-only --diff-filter=ACMR | grep -E "\.(c|cpp|h)$"`
for FILE in $FILES; do
    printf "\n%s\n" $FILE
    nf=`git checkout-index --temp $FILE | cut -f 1`
    newfile=`mktemp /tmp/${nf}.XXXXXX` || exit 1
    $CLANG_FORMAT $nf > $newfile 2>> /dev/null
    $DIFF -u -p -B  "${nf}" "${newfile}"
    r=$?
    rm "${newfile}"
    rm "${nf}"
    if [ $r != 0 ] ; then
        echo "[!] $FILE does not follow the consistent coding style." >&2
        RETURN=1
    fi
done

if [ $RETURN -eq 1 ]; then
    echo "" >&2
    echo "Make sure you indent as the following:" >&2
    echo "    clang-format -i $FILE" >&2
    echo
fi

exit $RETURN
