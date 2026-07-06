FROM ubuntu:22.04
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    clang-format \
    cppcheck \
    git \
    ca-certificates \
    build-essential \
    curl \
    && rm -rf /var/lib/apt/lists/*

COPY run_checks.sh /run_checks.sh
RUN chmod +x /run_checks.sh

ENTRYPOINT ["/run_checks.sh"]
