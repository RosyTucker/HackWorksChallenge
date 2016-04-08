#!/usr/bin/env bash

if [ -z $1 ];
then
  echo "You must specify your device name"
  exit 1
fi;

rm photon_firmware_*

result=$(particle compile photon ./firmware)

echo "$result"

set -e

output=$(echo "$result" | tail -1 | grep -o photon_firmware_.*\.bin)
echo "Created firmware: $output"
particle flash $1 $output
