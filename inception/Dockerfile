# test: 이미지생성: docker build . -t 생성이미지이름


FROM alpine:3.14

WORKDIR /

RUN apk update
RUN apk upgrade
RUN apk add vim nginx openssl

# ENTRYPOINT [ "bash", "init.sh" ]

# 컨테이너생성: docker run -it -p 80:80 --name "container_name" image_name