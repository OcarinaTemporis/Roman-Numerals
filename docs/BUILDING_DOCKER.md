# Building using Docker

## 1. Setup requirements

To use Docker, you'll need either Docker Desktop or Docker Toolbox installed and setup based on your system.

On Ubuntu, Docker and required tools can be installed with: `sudo apt install docker.io docker-compose docker-buildx`

You'll also need to prepare a local version of the project with a copied base ROM (see steps [2](../README.md#2-clone-the-repository) and [3](../README.md#3-prepare-a-base-rom) of the Linux instructions).

## 2. Create and start the Docker image build

From the root of your local project, run the following command:

```bash
DOCKER_UID=$(id -u) DOCKER_GID=$(id -g) docker-compose up --build
```

The compose service runs as the host user so generated files in the mounted project directory remain editable. The defaults are UID/GID 1000; set `DOCKER_UID` and `DOCKER_GID` explicitly when your host user has different IDs.

This should immediately begin steps [4](../README.md#4-setup-the-rom-and-build-process) and [5](../README.md#5-build-the-rom) within the Docker container.

## 3. Shell into the 'oot' container

To exec into the oot Docker image at any time, run the following command either during or after the build:

```bash
docker-compose exec oot bash
```
