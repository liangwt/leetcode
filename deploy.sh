#!/usr/bin/env sh

set -e

vuepress build docs

cd docs/.vuepress/dist

echo 'leetcode.showthink.cn' > CNAME

git init
git add -A
git commit -m 'deploy'

git push -f git@github.com:liangwt/leetcode.git master:gh-pages

cd -