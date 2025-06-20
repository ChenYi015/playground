# Define an argument for the base image.
# One can specify a different base image by adding `--build-arg BASE_IMAGE=xxx` flag when `docker build` the image.
ARG BASE_IMAGE=alpine:3.22.0

# Build from the specified base image.
FROM ${BASE_IMAGE}

# Metadata
LABEL KEY1=VALUE1 KEY2=VALUE2

ENV NAME="World"

# Set the working directory.
WORKDIR /opt/

# Copy the entrypoint script into container.
COPY hello.sh /opt/hello.sh

# Make the entrypoint script executable.
RUN chmod +x /opt/hello.sh

# The default command to run when the container starts.
# One can override the default entrypoint by adding `--entrypoint` flag when `docker run` the container.
ENTRYPOINT ["/opt/hello.sh"]
