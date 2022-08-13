# Testing

Filter out a specific test:

```bash
$ ninja && (./tests/tests --test-case=SOC --subcase=Clock)
```

Show all successes:

```bash
$ ninja && (./tests/tests --success)
```
