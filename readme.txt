--应用github管理《c++ primer》的课程代码
1. 将课程的代码工程clone至本地
   git clone https://github.com/hitskyer/course.git
2. 建立属于自己的代码目录
   cd course/c/ && mkdir "your name"(for example : xuxingjun)
3. 上传若干文件
   a) cd "your name"(for example : xuxingjun)
   b) mkdir chapter01 && cd chapter01
   c) cp ../../xuxingjun/chapter01/*cpp ./
   c) git add *cpp
   d) git commit -m "将xuxingjun在chapter01中的源代码拷贝至我的对应目录下"
   e) git push(failed: git pull && git push)
4. git的作用
   a) 从服务器上克隆完整的Git仓库（包括代码和版本信息）到单机上
   b) 在自己的机器上根据不同的开发目的，创建分支，修改代码
   c) 在单机上自己创建的分支上提交代码
   d) 在单机上合并分支
   e) 把服务器上最新版的代码fetch下来，然后跟自己的主分支合并
   f) ...
5. git的参考链接：https://baike.baidu.com/item/GIT/12647237
6. git的现阶段常用命令
   a) git clone "your url"
   b) git add "your file"
   c) git commit -m "your comment"
   d) git push
   e) git pull
