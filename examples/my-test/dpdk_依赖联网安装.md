# 编译dpdk
dpdk版本从19.11版本开始，官方文档开始使用meson ninja两个命令编译安装dpdk，在20.11版本开始删除了/usertools/dpdk-setup.py。所以建议从19.11版本后使用最新的编译方式。

## 裸机需要安装的依赖 

```powershell
# dpdk-22.07需要python >=3.7
# 源码编译python 3.7
1.安装依赖
yum -y install zlib-devel bzip2-devel openssl-devel ncurses-devel sqlite-devel readline-devel tk-devel gdbm-devel db4-devel libpcap-devel xz-devel libffi-devel gcc
2.下载Python3.7源码
1)下载
wget http://www.python.org/ftp/python/3.7.1/Python-3.7.1.tar.xz
2)解压
# tar -xvf Python-3.7.1.tar.xz && cd Python-3.7.1/
3. 执行配置文件，编译，编译安装
./configure --prefix=/usr/local/python37
 make && make install
4.建立软连接
mv /usr/bin/python /usr/bin/python_bak
ln -s /usr/local/python37/bin/python3.7 /usr/bin/python
ln -s /usr/local/python37/bin/pip3.7 /usr/bin/pip
```

```powershell
# 安装dpdk依赖
yum -y install numactl numactl-devel
pip3 install --user meson    # 用户权限安装
pip3 install --user ninja  
pip3 install pyelftools --upgrade

```


## 编译步骤
```powershell
tar xJf dpdk-22.07.tar.xz
cd dpdk-22.07
meson  build   （meson -Dbuildtype=debug build 编译debug版本）
cd build
ninja
 
后面的命令是安装命令，这个按需使用
ninja install
ldconfig



```

# 编译example
```powershell
cd dpdk-<version>
meson -Dexamples=flow_filtering  build 
 
cd build 
ninja

#flow_filtering编译后的可执行程序是 build/examples/dpdk-flow_filtering
#备注：build 目录存在需要先删除或者重新配置 "meson --reconfigure -Dexamples=flow_filtering build"
```


#
```txt

drivers:
        common/mvep:    missing dependency, "libmusdk"
        common/mlx5:    missing dependency, "mlx5"
        net/af_xdp:     missing header, "linux/if_xdp.h"
        net/ipn3ke:     missing dependency, "libfdt"
        net/mlx4:       missing dependency, "mlx4"
        net/mlx5:       missing internal dependency, "common_mlx5"
        net/mvneta:     missing dependency, "libmusdk"
        net/mvpp2:      missing dependency, "libmusdk"
        net/nfb:        missing dependency, "libnfb"
        net/sfc:        missing dependency, "libatomic"
        raw/ifpga:      missing dependency, "libfdt"
        raw/ioat:       replaced by dmadev drivers
        crypto/armv8:   missing dependency, "libAArch64crypto"
        crypto/ipsec_mb:        missing dependency, "libIPSec_MB"
        crypto/mlx5:    missing internal dependency, "common_mlx5"
        crypto/mvsam:   missing dependency, "libmusdk"
        compress/isal:  missing dependency, "libisal"
        compress/mlx5:  missing internal dependency, "common_mlx5"
        regex/mlx5:     missing internal dependency, "common_mlx5"
        vdpa/mlx5:      missing internal dependency, "common_mlx5"
        gpu/cuda:       missing dependency, "cuda.h"
```
```powershell
   yum -y install libdpdk-dev 
```


# dpdk 运行helloword 
[第一个dpdk程序](https://wangquan.blog.csdn.net/article/details/120822519?spm=1001.2101.3001.6650.12&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-12-120822519-blog-123949863.pc_relevant_aa&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-12-120822519-blog-123949863.pc_relevant_aa&utm_relevant_index=14)



# 问题
```txt
1. 源码编译python3，创建软连接导致
[root@localhost ~]# yum install libhugetlbfs
  File "/usr/bin/yum", line 30
    except KeyboardInterrupt, e:
                            ^
SyntaxError: invalid syntax
2.解决办法
vi /usr/bin/yum
!/usr/bin/python2.7   //修改成2.7
vi /usr/libexec/urlgrabber-ext-down
!/usr/bin/python2.7   //修改成2.7
```

# DPDK执行相关参数
[DPDk执行相关参数](https://www.jianshu.com/p/b2b2b8edfeaa)
