def safe_print_integer_err(value):
    try:
        print("{:d}".format(value))
        return True
    except (ValueError, TypeError) as e:
        import sys
        print("Exception:", e, file=sys.stderr)
        return False
