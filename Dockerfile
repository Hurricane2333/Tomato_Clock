# 基础镜像
FROM ubuntu:noble

# 禁止交互
ENV DEBIAN_FRONTEND=noninteractive

# 设置时区
ENV TZ=Asia/Shanghai
RUN ln -fs /usr/share/zoneinfo/$TZ /etc/localtime && \
    echo $TZ > /etc/timezone && \
    apt-get update && \
    apt-get install -y tzdata

# 设置工作目录
WORKDIR /app

# 更新安装包列表并安装必要的依赖
RUN apt-get update && apt-get install -y \
    build-essential \
    qt6-base-dev \
    qt6-charts-dev \
    qt6-multimedia-dev \
    libsqlite3-dev \
    && rm -rf /var/lib/apt/lists/*

# 复制项目文件
COPY . /app

# 使用 qmake6 生成 Makefile 并编译项目
RUN qmake6 Tomato_Clock.pro \
    && make

# 容器启动时执行命令
# CMD ["./Tomato_Clock"]
