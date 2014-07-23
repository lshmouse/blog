#!/bin/bash

echo "Start to deploy lshmouse's blog to github"
make html
git branch -D gh-pages
git checkout -b gh-pages origin/gh-pages
rsync -a _build/html/ .
git add .
git commit -m "deploy lshmouse's blog at `date`"
git push origin
git checkout master
git branch -D gh-pages
rm _build
echo "Deploy success!"
echo "See: http://lshmouse.github.io/blog/"

