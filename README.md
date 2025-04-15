# meson-python-reproducer646

This is a minimal reproducer for the issue reported at https://github.com/mesonbuild/meson-python/issues/646 .

It features a simple "Hello World"-like python package configured with meson-python (directly inspired from the [meson-python tutorial](https://mesonbuild.com/meson-python/tutorials/introduction.html)).

It also features a pytest setup with failing assertions, that highlight how `pytest` assertion rewriting fails in some cases.

The pytest pipeline is ran in a github action, its logs showcase directly the issue.

Or you can try to reproduce locally, provided a working python environment, clone this repository and run those commands from the root:

```bash
python -m venv reproducer646_venv
source reproducer646_venv/bin/activate
pip install -e .[dev] -c contraints-dev.txt
python -m pytest
```

If you see tests that output

```
_____________________________________________________________________________________________________________ test_foo _____________________________________________________________________________________________________________

    def test_foo():
>       assert foo() == "baz"
E       AssertionError

src/reproducer646/test/test_some_module2.py:5: AssertionError
```

then assertion rewriting fails.

Assertion rewriting works when you see:

```
_____________________________________________________________________________________________________________ test_foo _____________________________________________________________________________________________________________

    def test_foo():
>       assert foo() == "baz"
E       AssertionError: assert 'bar' == 'baz'
E
E         - baz
E         + bar

tests/test_some_module.py:5: AssertionError
```

This project provides two times the same test located on different location (either ./tests or ./src/reproducer646/test/ folders) to test pytest behavior in different setups.
