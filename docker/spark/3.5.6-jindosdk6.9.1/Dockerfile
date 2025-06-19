ARG SPARK_IMAGE=spark:3.5.6

FROM ${SPARK_IMAGE}

# Add dependency for JindoSDK support
ADD --chown=spark:spark --chmod=644 https://jindodata-binary.oss-cn-shanghai.aliyuncs.com/mvn-repo/com/aliyun/jindodata/jindo-core/6.9.1/jindo-core-6.9.1.jar ${SPARK_HOME}/jars
ADD --chown=spark:spark --chmod=644 https://jindodata-binary.oss-cn-shanghai.aliyuncs.com/mvn-repo/com/aliyun/jindodata/jindo-sdk/6.9.1/jindo-sdk-6.9.1.jar ${SPARK_HOME}/jars
