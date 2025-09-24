#!/bin/sh

git filter-branch --env-filter '
OLD_EMAIL="lismarti"
CORRECT_NAME="Lisa Martin"
CORRECT_EMAIL="lisa.martin.lm02@gmail.com"

if [ "$GIT_COMMITTER_EMAIL" = "$OLD_EMAIL" ] || echo "$GIT_COMMITTER_EMAIL" | grep -q "^$OLD_EMAIL"; then
    export GIT_COMMITTER_NAME="$CORRECT_NAME"
    export GIT_COMMITTER_EMAIL="$CORRECT_EMAIL"
fi
if [ "$GIT_AUTHOR_EMAIL" = "$OLD_EMAIL" ] || echo "$GIT_AUTHOR_EMAIL" | grep -q "^$OLD_EMAIL"; then
    export GIT_AUTHOR_NAME="$CORRECT_NAME"
    export GIT_AUTHOR_EMAIL="$CORRECT_EMAIL"
fi
' --tag-name-filter cat -- --branches --tags
