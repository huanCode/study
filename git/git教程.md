#查看commit历史
>git log

#状态切换
1. 变回untracked
git rm --cached 文件名

#branch
1. 查看当前哪个分支
git log --online --decorate

1. 切换分支
git checkout 分支名

1. 创建分支
git checkout -b 分支名

1. 合并分支
git checkout master
git merge 分支名 ,把分支去掉,合并成master

1. 删除分支
git checkout master
git branch -d 分支名,删除分支,用master取代


##合并之-并
如果两个分支合并时,两个分支没有共同的文件不同内容时，合并后直接删除另个分支
>场景：master、test
git checkout master
git merge test
git branch -d test

##合并之-交
如果两个分支合并时,两个分支有共同的文件不同内容时

##分支管理
1. 查看每个分支最后commit
git branch -v


#sourcetree软件
untracked file
![](.png)
