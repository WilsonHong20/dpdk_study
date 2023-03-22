# CPU FT-2000/4
# ZFP2206
# 编译依赖
python > 3.7  源码编译
meson-1.0.1-py3-none-any.whl
ply-3.11.py2.py3.none-any-whl
pyelftools-0.29-py2.py3-none-any.whl
setuptools-67.5.0-py3-none-any.whl
wheel-0.38-py3-none-any.whl
# 编译
```powershell
 #修改dpdk.mk  :删掉meson==0.55的两行
cd ./vpp-22.06
make install-ext-deps-deb
```
