# Mega Drive PSG Envelopes [![CircleCI](https://circleci.com/gh/rhargreaves/mega-drive-psg-envelopes.svg?style=svg)](https://circleci.com/gh/rhargreaves/mega-drive-psg-envelopes) [![GitHub release (latest by date)](https://img.shields.io/github/v/release/rhargreaves/mega-drive-psg-envelopes?style=plastic)](https://github.com/rhargreaves/mega-drive-psg-envelopes/releases)

Builds a ROM which probably makes a horrible noise. Mostly for experimenting with programming software-driven PSG envelopes for defining PSG instruments for the [Mega Drive MIDI Interface](https://github.com/rhargreaves/mega-drive-midi-interface).

## Build

Docker:

```sh
./docker-make
```

Linux (requires `cmake` & [gendev](https://github.com/kubilus1/gendev)):

```sh
make
```
