echo making rootCA...
openssl req -new -newkey rsa:4096 -sha256 -nodes -keyout sashin-ssl.key \
-x509 -days 90 -subj "/C=KR/ST=Seoul/L=podong_podong_Gaepo-dong/O=42seoul/OU=Cluster/CN=localhost" -out sashin-ssl.crt
mv sashin-ssl.key /etc/ssl/private
mv sashin-ssl.crt /etc/ssl/certs

exec nginx