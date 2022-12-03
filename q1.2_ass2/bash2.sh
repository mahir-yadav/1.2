#!/bin/bash
cd ../build/linux-5.9.19
make -j2
make modules_install
