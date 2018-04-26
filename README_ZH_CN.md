> 建立这个仓库的目的主要有两个：
>>  - 更好地学习C/C++ 
>>  - 熟练使用GitHub，掌握MarkDown这种轻量级的标记语法

## 开发环境
我所使用的开发环境：
- 系统环境
- [x] macOS 10.13.4 目前主要系统
- [x] Ubuntu 17.10 以前用得比较多，无奈校园网没客户端。
- [x] CentOS 7 安装在服务器上面的，有两个，` Vultr ` 和 ` Aliyun `
- [ ] Windows 这个系统我不太喜欢用，比较喜欢使用文本系统

- 编译器:
- [x] GCC

- 代码编辑器
- [x] Vim
- [x] SublimeText 3
- [x] Nodepad++

- Terminal美化
- [x] zsh
- [x] powerline-theme
- [x] vim-airline


个人比较喜欢在 ***Terminal*** 下面使用` gcc/g++ `编译源代码。

### 环境配置(以macOS为例)
- 安装` Homebrew `-从Linux过渡

在` Terminal `下面输入以下命令：

```bash
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```
可能会要求重复多次输入管理员密码，切记不要切换` root `用户，否则无法安装

- 安装` Git `-熟悉Git命令更好利用GitHub

可以到Git官网下载安装包，不过我更推荐使用` Homebrew `从源安装，同样在` Terminal `键入以下命令：

```bash
brew update    #从软件仓库更新软件列表
brew install git  #安装git
```

- 安装` wget `下载工具-下载更方便
虽然系统自带` Curl `,不过还是推荐安装` wget `和` aria2c `

安装wget
```bash
brew install wget  #安装wget
```
源码编译安装` Aria2c `
```bash
cd ~/Desktop   #进入用户桌面文件夹
git clone https://github.com/aria2/aria2.git     #克隆仓库到本地，前提是安装好git
cd aria2    #进入aria2文件夹，即远程同步下来的源码文件夹
./configure     #检查配置环境
./configure ARIA2_STATIC=yes        #使用ARIA2_STATIC=yes
make    #编译源码
make install  #安装
```

- 安装` zsh `让你的终端更强大-高效

```bash
brew install zsh       #安装zsh
sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"  #github仓库更新安装
```

- 安装` Powerline-theme `-美观、易用

```bash
git clone https://github.com/jeremyFreeAgent/oh-my-zsh-powerline-theme.git
./install_in_omz.sh
cd ~
vi .zshrc      #编辑zsh配置文件，找到主题设置并修改为ZSH_THEME="powerline"
```

- 更新gcc-自带gcc太旧无法满足大部分项目需要
1. 查询` brew `仓库默认gcc版本，[查询](http://formulae.brew.sh/)，在搜索🔍框里输入` gcc `,目前默认为` -version 7.3.0_1 `
2. 终端输入` brew install gcc `
3. 终端安装完毕，编辑shell配置文件启用
```bash
cd ~
vi .zshrc   #我使用的是zsh，所以编辑这个文件
```
添加下面几条，为` gcc-7 `设置别名
```bash
#gcc -version
alias gcc="gcc-7"
alias g++="g++-7"
```



- 安装` Airline `-Vim会更强

```bash
cd ~     #进入用户目录
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim    #安装Vundle插件管理工具
vi .vimrc
```
编辑vim配置文件，添加：
```bash
set nocompatible              " be iMproved, required
filetype off                  " required

set rtp+=~/.vim/bundle/Vundle.vim

call vundle#begin()

Plugin 'VundleVim/Vundle.vim'

Plugin 'vim-airline/vim-airline'

Plugin 'vim-airline/vim-airline-themes'

call vundle#end()            " required

filetype plugin indent on    " required

set nu            " 显示行号
```
Terminal下输入` vim `
在非插入状态下输入` :PluginInstall `安装插件。

更多软件推荐，详见[博客](https://ourfor.top)

***ourfor.top***





